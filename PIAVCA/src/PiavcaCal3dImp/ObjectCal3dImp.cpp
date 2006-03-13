
#include "ObjectDiveImp.h"

#include "PiavcaAPI/Object.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/Quat.h"
#include "DiveMathsConversion.h"

using namespace Piavca;

#include <algorithm>
using std::cout;
using std::endl;

extern "C" 
{
void
basic_transform_execute(dive_obj *obj, point_t R[3], point_t T[1],
			coord_type option, objid_t *rel_id, objid_t *origin,
			unsigned int flags,
			point_t *oldT, divetime **time);
void
basic_transform_complete(dive_obj *obj, unsigned int flags, point_t *oldT,
			 divetime *time, objid_t *origin);
}

void	ObjectDiveImp::setPosition (const Vec &Position)
{
  //cout << "in set root position\n";
  divetime time;
  divetime_get(&time);
  divetime *pTime;
  point_t T;
  dive_obj *root_obj;
  point_t old_T;

  root_obj = find_object(&root_id);
  if(root_obj == NULL)
  {
       Piavca::Error("Could not find root object in setRootPosition");
	   return;
  }
  vectodive(Position, T);
  
  
  basic_transform_execute(root_obj, diveobj_R0(root_obj, &time), &T, 
			  WORLD_C, NULL, &root_id, TRANSFORM_ABS,
			  &old_T, &pTime);
  basic_transform_complete(root_obj, TRANSFORM_ABS, &old_T, pTime, &root_id);
  
}
Vec		ObjectDiveImp::getPosition ()
{
	// What root? root of the object? in which case shouldn't I be getting the ID?
  // ObjectImp->root_id = find_sub_byname(&ObjectImp->top_id, "body");
  // ObjectImp->root_node = find_object(ObjectImp->root_id);

   divetime time;
   divetime_get(&time);
   
   dive_obj *root_obj;
   point_t *T;
   
   root_obj = find_object(&root_id);
   if(root_obj == NULL)
   {
       Piavca::Error("Could not find root object in getRootPosition");
	   return Vec();
   }
   T 				= diveobj_T0(root_obj, &time);

	 //cout << "UCLObjectDiveImp: Root Position:" << T->x << " " << T->y << " " << T->z << endl; 
  return Vec(T->x, T->y, T->z);
}
void	ObjectDiveImp::setOrientation	(const Quat &Orientation)
{
	//std::cout << Orientation << std::endl;

  divetime time;
  divetime_get(&time);
  divetime *pTime;
  point_t R[3];
  dive_obj *root_obj;
  point_t old_T;
		
  root_obj = find_object(&root_id);
   if(root_obj == NULL)
   {
       Piavca::Error("Could not find root object in setRootOrientation");
	   return;
   }
  quattomat(Orientation, R);
  
  basic_transform_execute(root_obj, R, diveobj_T0(root_obj, &time), 
			  WORLD_C, NULL, &root_id, TRANSFORM_ABS,
			  &old_T, &pTime);
  basic_transform_complete(root_obj, TRANSFORM_ABS, &old_T, pTime, &root_id);

};
Quat	ObjectDiveImp::getOrientation ()
{	
   divetime time;
   divetime_get(&time);
   
   dive_obj *root_obj;
   point_t *R;
   
   Quat Q;
   
   root_obj = find_object(&root_id);
   if(root_obj == NULL)
   {
       Piavca::Error(_T("Could not find root object in getRootOrientation"));
	   return Q;
   }
   R  = diveobj_R0(root_obj, &time);
   //vecprintmatrix(R);
   
   mattoquat(R, Q);
   Q.normalise();
   return Q;
};


void ObjectDiveImp::scale(Vec scale)
{
	// only do anything if the scale factor has actually changed
	// (its an expensive operation in DIVE)
	Vec distance = scale - rootScale;
	if(distance.mag() > 0.00001)
		return;;
	point_t ratio;
	ratio.x = scale.X()/rootScale.X();
	ratio.y = scale.Y()/rootScale.Y();
	ratio.z = scale.Z()/rootScale.Z();
	distr_scale(&root_id, &ratio, &Actor->id);
	rootScale = scale;
}
