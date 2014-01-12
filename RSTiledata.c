#include <RSTiledata.h>


int RSTiledataThingTypeIsClosedWay(RSTiledataThingType thingType) {
    switch (thingType) {

        case RSTiledataBuilding:
            return 1;

        case RSTiledataHighwayMotorway:
        case RSTiledataHighwayPrimary:
        case RSTiledataHighwaySecondary:
        case RSTiledataHighwayTertiary:
        case RSTiledataHighwayResidential:
        case RSTiledataHighwayService:
            return 0;
    }
}
