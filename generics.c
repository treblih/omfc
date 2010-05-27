/*
 * =====================================================================================
 *
 *       Filename:  generics.c
 *
 *    Description:  all global functions for OMFC
 *
 *        Version:  1.0
 *        Created:  31.03.10
 *       Revision:  
 *       Compiler:  GCC 4.4.3
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#define		GENERICS_IMPLEMENTATION
#include	<omfc/omfc.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  galloc
 *  Description:  allocate the space
 *
 *  		  if a global class indicator is < gheap ==> 
 *  		  the class descriptor is not in memory yet, so just a init() pointer
 *  		  so exe the instructions firstly
 *  		  then allocate the space guided in the class descriptor -- .size
 *
 *  		  resign every obj.class to it's meta class
 * =====================================================================================
 */
OBJ galloc(OBJ _cls)
{
        CLS cls = gcast(Class, _cls);     
	OBJ obj = calloc(1, cls->size);                 /* make it clean */
	obj->class = (OBJ)cls;                          /* SIGNIFICANT */
	return obj;                                     /* return the calloc'd one */
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ginit
 *  Description:  lazy binding, dynamic linkage
 *  		  call it's corresponding ctor to init the new obj
 *  		  got the obj which need initialising from galloc()
 * =====================================================================================
 */
OBJ ginit(OBJ _obj, ...)
{
	va_list arg;
	va_start(arg, _obj);
	CLS cls = gcast(Class, gclass_of(_obj));
	OBJ obj = cls->ctor(_obj, arg);
	va_end(arg);

	/*-----------------------------------------------------------------------------
	 *  can't use $do(_obj, ctor, $arg(_arg)); here
	 *  struct Object has no 'ctor'
	 *-----------------------------------------------------------------------------*/
	return obj;
}

OBJ vginit(OBJ _obj, va_list _arg)
{
	CLS cls = gcast(Class, gclass_of(_obj));
	OBJ obj = cls->ctor(_obj, _arg);

	/*-----------------------------------------------------------------------------
	 *  can't use $do(_obj, ctor, $arg(_arg)); here
	 *  struct Object has no 'ctor'
	 *-----------------------------------------------------------------------------*/
	return obj;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  delete
 *  Description:  lazy binding, dynamic linkage
 *  		  call it's corresponding dtor to destruct 
 *  		  then free the obj
 * =====================================================================================
 */
void gdelete(OBJ _obj)
{
	if (_obj) {
		
		/*-----------------------------------------------------------------------------
		 *  can't be $pri(Class)
		 *  private_Class_interface has no component, for the room of next generation
		 *  see generics.h
		 *-----------------------------------------------------------------------------*/
		$private(Class) obj = (PTR) _obj;
		$do(obj, dtor);
		free(_obj);
	}
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  gsize_of
 *  Description:  a object may not have it's size element, so can't "->size" directly
 *  		  but it was generated by it's class-desc, so it has the record of
 *  		  the object
 * =====================================================================================
 */
#if 0
size_t gsize_of(OBJ _obj)
{
	CLS cls = gcast(Class, gclass_of(_obj));
	return cls->size;
}

BOOL gis_of(OBJ _down, OBJ _up)
{
	if (_up == Nil) {
		return false;
	}

	OBJ cls;
	while (_down != Nil) {
		if (_up == (cls = gclass_of(_down))) {
			 return true;
		} else {
			_down = cls;
		}
	}
	return false;
}
#endif

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ginit_class
 *  Description:  wrapped by every init() in every class.c
 *  		  init the class descriptor
 * =====================================================================================
 */
void ginit_class(OBJ _sub, OBJ _spr, size_t _copy_len, size_t _private_len, int _ovwt, ...)
{
	memcpy(_sub, _spr, _copy_len);                  /* steal all */

	/*-----------------------------------------------------------------------------
	 *  start to change all data copied from super class to it's independences
	 *-----------------------------------------------------------------------------*/
	CLS cls = gcast(Class, _sub);
	cls->size = _private_len;                       /* private data struct size */

	va_list arg;
        va_start(arg, _ovwt);                           /* pair is the sentinel, essential */
	off_t offset;
	PTR sub = (PTR) _sub;
	FUNC * ptr;

	/*-----------------------------------------------------------------------------
	 *  new func addr overlay the copied, or init the new one to the class
	 *-----------------------------------------------------------------------------*/
	for (int i = 0; i < _ovwt; i += 1) {
		offset = va_arg(arg, off_t);
                ptr = (FUNC *) (sub + offset);          /* posit */
                *ptr = va_arg(arg, FUNC);               /* modify */
	}

	/*-----------------------------------------------------------------------------
	 *  alias, in fact it's a new slot in the class descriptor, and copy the orignal
	 *  func pointer to there
	 *-----------------------------------------------------------------------------*/
	off_t new_off;
	off_t ori_off;
	int alias = va_arg(arg, int);
	/* assert(alias < 10); */
	for (int i = 0; i < alias; i += 1) {
		new_off = va_arg(arg, off_t);
		ori_off = va_arg(arg, off_t);
		memcpy(sub + new_off, sub + ori_off, sizeof(FUNC));
	}
	va_end(arg);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  gimplicit
 *  Description:  show only in $onstk()
 *  		  make ... in a macro to extract to __VA_ARGS__
 * =====================================================================================
 */
OBJ gimplicit(OBJ _obj, ...)
{
	va_list ap;
	va_start(ap, _obj);
        return ginit(_obj, ap);                         /* no ';' */
}
