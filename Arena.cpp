#include "Arena.h"

Arena::Arena(IVideoDriver* driver, ISceneManager* smgr)
{

    smgr->setAmbientLight(SColorf(.7, .7, .6));
    smgr->setShadowColor(SColor(100,0,0,0));

    // appearance 0
    sky[0] = smgr->addSkyDomeSceneNode(driver->getTexture("data/skydome.jpg"), 16, 8, 0.95, 2.0);
    sun[0] = smgr->addLightSceneNode(0, vector3df(0, 500, 0), SColorf(.6, .6, .4), 512);
    terrain[0] = smgr->addTerrainSceneNode("data/heightmap.png", 0, -1,
                                           vector3df(-512, 0, -512),
                                           vector3df(0.0, 0.0, 0.0),
                                           vector3df(2.0, 0.5, 2.0),
                                           SColor(255, 50, 180, 20),
                                           4, ETPS_9, 0, false);
    terrain[0]->setMaterialTexture(0, driver->getTexture("data/grass1.jpg"));
    terrain[0]->scaleTexture(12, 12);

    // appearance 1
    sky[1] = smgr->addSkyBoxSceneNode(
                 driver->getTexture("data/irrlicht2_up.jpg"),
                 driver->getTexture("data/irrlicht2_dn.jpg"),
                 driver->getTexture("data/irrlicht2_lf.jpg"),
                 driver->getTexture("data/irrlicht2_rt.jpg"),
                 driver->getTexture("data/irrlicht2_ft.jpg"),
                 driver->getTexture("data/irrlicht2_bk.jpg"));
    sun[1] = smgr->addLightSceneNode(0, vector3df(0, 500, 0), SColorf(.6, .6, .4), 512);
    terrain[1] = smgr->addTerrainSceneNode("data/heightmap.png", 0, -1,
                                           vector3df(-512, 0, -512),
                                           vector3df(0.0, 0.0, 0.0),
                                           vector3df(2.0, 0.5, 2.0),
                                           SColor(255, 100, 20, 20),
                                           4, ETPS_9, 0, false);
    terrain[1]->setMaterialTexture(0, driver->getTexture("data/dirt1.jpg"));
    terrain[1]->scaleTexture(12, 12);

    appearance = 0;
    setAppearance(appearance);
}

int Arena::getAppearance()
{
    return appearance;
}

void Arena::setAppearance(int number)
{
    appearance = number;
    for (int i=0; i<numAppearances; i++)
    {
        if (i==number)
        {
            sky[i]->setVisible(true);
            sun[i]->setVisible(true);
            terrain[i]->setVisible(true);
        }
        else
        {
            sky[i]->setVisible(false);
            sun[i]->setVisible(false);
            terrain[i]->setVisible(false);
        }
    }
}
