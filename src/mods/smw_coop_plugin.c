#include "mod_runtime.h"
#include "recomp_launcher.h"
#include "mods/coop/coop_runtime.h"
#include <stdlib.h>
#include <string.h>
#define PACKAGE "super-mario-world.gameplay.native-coop"
static void reset_coop(void) {SmwCoopEnable(false);SmwCoopSetRosterSize(2);}
static void activate_coop(void) {
    unsigned players=2;
    const RecompLauncherCModProvider *p=snes_mod_runtime_launcher_provider_c();
    if(p && p->feature_option_get) {
        RecompLauncherCModOption option;
        for(int i=0;i<16;++i) {
            memset(&option,0,sizeof(option));
            if(!p->feature_option_get(p->ctx,PACKAGE,"simultaneous",i,&option))break;
            if(!strcmp(option.id,"players"))players=(unsigned)strtoul(option.value,NULL,10);
        }
    }
    /* Isolated QA override, matching the other mods' environment hooks. */
    const char *env=getenv("SMW_COOP_PLAYERS");
    if(env && *env)players=(unsigned)strtoul(env,NULL,10);
    SmwCoopSetRosterSize(players);
    SmwCoopEnable(true);
}
SNES_MOD_CONSTRUCTOR(smw_register_native_coop_plugin) {
    (void)snes_mod_register_reset_callback(reset_coop);
    (void)snes_mod_register_activation_plugin("super-mario-world.native-coop",activate_coop);
}
