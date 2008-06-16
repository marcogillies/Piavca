/* LICENCE BLOCK
PiavcaOpenSGCore.cpp
Copyright (C) 2005 Marco (Mark) Gillies

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllimport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "PiavcaOpenSGCore.h"
#include "PiavcaAPI/PiavcaDefs.h"
#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/KeyframeMotion.h"

#include "OSGCharacterModel.h"

 #include <OpenSG/OSGSimpleAttachments.h>

using namespace Piavca;


#include <fstream>
#include <assert.h>
#include <algorithm>



#include <time.h>


#ifdef _WIN32
#include <windows.h>
#endif

#if defined(__APPLE__)
	#include <OpenGL/gl.h>
#else
	#include <GL/gl.h>
#endif

//Core *Core::init()
//{
//	return new PiavcaOpenSGCore();
//};

PiavcaOpenSGCore::PiavcaOpenSGCore(osg::NodeRefPtr root):graph_root(root)
{
};

AvatarOpenSGImp *PiavcaOpenSGCore::createAvatarImp(osg::CharacterPtr character, osg::NodeRefPtr node, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
{
	return new AvatarOpenSGImp(character, node, bailOnMissedJoints, Position, Orientation);
}
		

osg::Action::ResultE enter(osg::NodePtr& node)
{   
    //if (osg::getName(node))
	if (node->getCore()->getType().isDerivedFrom(OSG::CharacterBase::getClassType()))
    {
		std::cout << osg::getName(node) << "is a character" << std::endl;
    }
    //else
	//{
    //     std::cout << osg::getName(node) << "is not a character" << std::endl;
	//}

    return osg::Action::Continue; 
}



namespace Piavca
{
// A class for finding Character nodes in the osg scene graph
class NodeFinder{
        public:
                //constructor 
			NodeFinder(PiavcaOpenSGCore * _core)
				:core(_core)
				{
                }

			AvatarImp *createImp(osg::CharacterPtr charac, osg::NodePtr&node)
			{
				return core->createAvatarImp(charac, osg::NodeRefPtr(node), false, Vec(), Quat());
			}

			virtual osg::Action::ResultE process(osg::NodePtr& node, osg::CharacterPtr charac, std::string name)=0;
                
            //method that will be called when entering
            //a new node
			osg::Action::ResultE enter(osg::NodePtr& node)
			{
                if (node->getCore()->getType().isDerivedFrom(OSG::CharacterBase::getClassType()))
				{
					osg::CharacterPtr charac = osg::CharacterPtr::dcast(node->getCore());
					std::string name;
					if (getName(node))
					{
						name = getName(node);
					}
					else 
					{
						osg::CharacterModelPtr model = charac->getModel();
						name = model->getConfigFile();
						std::cout << "character model file " << name << std::endl;
						std::string::size_type slashpos = name.size()-1;
						slashpos = name.find_last_of("/");
						if(slashpos != name.npos)
							name = name.substr(slashpos+1);
						slashpos = name.size()-1;
						slashpos = name.find_last_of("\\");
						if(slashpos != name.npos)
							name = name.substr(slashpos+1);
						std::string::size_type dotpos = 0;
						dotpos = name.find_last_of(".");
						if(dotpos != name.npos)
							name = name.substr(0, dotpos);
					}
					std::cout << name << " is a character" << std::endl;
					return process(node, charac, name);
				}
                return osg::Action::Continue;
            }
        
        protected:
				PiavcaOpenSGCore * core;
};

class NamedNodeFinder : public NodeFinder{
        public:
                //constructor 
			NamedNodeFinder(PiavcaOpenSGCore * _core, std::string searchString)
				:NodeFinder(_core), toSearchFor(searchString), imp(NULL)
			{
            }
                
			virtual osg::Action::ResultE process(osg::NodePtr& node, osg::CharacterPtr charac, std::string name)
			{
				if (name == toSearchFor)
				{
					imp = createImp(charac, node);
					return osg::Action::Quit;
				}
				else
					return osg::Action::Continue;
			};
            
                
            AvatarImp *getImp(void){
                    return imp;
            }
        
        private:
				AvatarImp *imp;
				std::string toSearchFor;
};


class AllNodeFinder : public NodeFinder{
        public:
                //constructor 
			AllNodeFinder(PiavcaOpenSGCore * _core)
				:NodeFinder(_core)
			{
            }
                
			virtual osg::Action::ResultE process(osg::NodePtr& node, osg::CharacterPtr charac, std::string name)
			{
				AvatarImp *imp = createImp(charac, node);
				Avatar *av = new Avatar(StringToTString(name), imp);
				core->loadAvatar(av);

				return osg::Action::Continue;
			};
        
        private:
};
}

AvatarImp *PiavcaOpenSGCore::createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
{
	
   std::cout << "in createAvatarImp\n";
   std::cout << avatarId << std::endl;

   NamedNodeFinder nfinder(this, TStringToString(avatarId));
   osg::traverse(graph_root, 
	   osg::osgTypedMethodFunctor1ObjPtrCPtrRef
	   <osg::Action::ResultE, NodeFinder, osg::NodePtr>(&nfinder, &NodeFinder::enter));
   
	return nfinder.getImp();
}

void PiavcaOpenSGCore::loadAllAvatars()
{
   AllNodeFinder nfinder(this);
   osg::traverse(graph_root, 
	   osg::osgTypedMethodFunctor1ObjPtrCPtrRef
	   <osg::Action::ResultE, NodeFinder, osg::NodePtr>(&nfinder, &NodeFinder::enter));		
};
