#ifndef __RSTiledata_header__
#define __RSTiledata_header__


typedef enum {
    RSTiledataBuilding = 1,
    RSTiledataHighwayMotorway = 2,
    RSTiledataHighwayPrimary = 3,
    RSTiledataHighwaySecondary = 4,
    RSTiledataHighwayTertiary = 5,
    RSTiledataHighwayResidential = 6,
    RSTiledataHighwayService = 7
} RSTiledataThingType;


int RSTiledataThingTypeIsClosedWay(RSTiledataThingType thingType);


#endif
