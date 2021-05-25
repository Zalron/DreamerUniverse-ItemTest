#define flecs_rest_STATIC
#ifndef FLECS_SYSTEMS_REST_H
#define FLECS_SYSTEMS_REST_H

/* This generated file contains includes for project dependencies */
/*
                                   )
                                  (.)
                                  .|.
                                  | |
                              _.--| |--._
                           .-';  ;`-'& ; `&.
                          \   &  ;    &   &_/
                           |"""---...---"""|
                           \ | | | | | | | /
                            `---.|.|.|.---'

 * This file is generated by bake.lang.c for your convenience. Headers of
 * dependencies will automatically show up in this file. Include bake_config.h
 * in your main project file. Do not edit! */

#ifndef FLECS_REST_BAKE_CONFIG_H
#define FLECS_REST_BAKE_CONFIG_H

/* Headers of public dependencies */
#include "flecs.h"
#include "flecs_components_http.h"
#include "flecs_meta.h"
#include "flecs_json.h"

/* Convenience macro for exporting symbols */
#ifndef flecs_rest_STATIC
#if flecs_rest_EXPORTS && (defined(_MSC_VER) || defined(__MINGW32__))
  #define FLECS_REST_API __declspec(dllexport)
#elif flecs_rest_EXPORTS
  #define FLECS_REST_API __attribute__((__visibility__("default")))
#elif defined _MSC_VER
  #define FLECS_REST_API __declspec(dllimport)
#else
  #define FLECS_REST_API
#endif
#else
  #define FLECS_REST_API
#endif

#endif


ECS_STRUCT(EcsRestServer, {
    int16_t port;
});

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FlecsRest {
    ECS_DECLARE_COMPONENT(EcsRestServer);
} FlecsRest;

FLECS_REST_API
void FlecsRestImport(
    ecs_world_t *world);

#define FlecsRestImportHandles(handles) \
    ECS_IMPORT_COMPONENT(handles, EcsRestServer); 

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef FLECS_NO_CPP

namespace flecs {

class rest : public FlecsRest {
public:
    using Server = EcsRestServer;

    rest(flecs::world& world) {
        FlecsRestImport(world.c_ptr());

        flecs::module<flecs::rest>(world, "flecs::rest");

        flecs::component<Server>(world, "Server");
    }
};

}

#endif // FLECS_NO_CPP
#endif // __cplusplus

#endif
