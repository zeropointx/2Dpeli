#include "SceneSys.h"
#include "Game.h"
#include "GameMenu.h"
#include <iostream>
vector<SceneParent*> SceneSys::scenes;
	static bool sceneChanged = false;

SceneParent SceneSys::GetScene(int p)
      {
		  int n = 0;
		   for (vector<SceneParent*>::iterator i; i != scenes.end(); i++)
          {
			  if(n == p)
				  return **i;
			  n++;
		   }
      }
void SceneSys::ChangeScene(SceneParent *scene)
      {
		   /* for (vector<SceneParent*>::iterator i = scenes.begin(); i != scenes.end();i++)
          {
			 delete (*i);
			 
			
			}*/
		  vector<SceneParent*>::iterator i = scenes.begin();
		  while(i != scenes.end())
		  {
			  delete (*i);
			  i = scenes.erase(i);
		  }
			cout<<scenes.size()<<endl;
          scenes.erase(scenes.begin(),scenes.end());
          OpenScene(scene);
      }
void SceneSys::OpenScene(SceneParent *scene)
{

	scenes.push_back(scene);
         // scene->Start();
          sceneChanged = true;
}
void SceneSys::Update(float dT)
      {
		  for (vector<SceneParent*>::iterator i = scenes.begin(); i != scenes.end(); i++)
          {
              if (!(*i)->_paused)
              {
                 (*i)->Update(dT);
                  if (sceneChanged)
                  {
                      sceneChanged = false;
                      break;
                  }
              }
          }
      
}
void SceneSys::Draw()
{
   for (vector<SceneParent*>::iterator i = scenes.begin(); i != scenes.end(); i++)
    {
		(*i)->Draw();
	}
          
        
}
void SceneSys::PauseCurrentScene(bool pause)
{
	if(scenes[scenes.size()-1]->_paused != pause)
	{
	scenes[scenes.size()-1]->_paused = pause;
	cout<<"Paused/Unpaused scene"<<endl;
	}
}