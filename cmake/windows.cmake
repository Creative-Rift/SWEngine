## IMPORTED SHARED LIBRARY NAME
set( SHARED_LIB_NAME
        glfw3
        )

## IMPORTED SHARED LIBRARY LOCATION
set( SHARED_LIB_LOCATION
        ${CMAKE_SOURCE_DIR}/external/${CMAKE_BUILD_TYPE}/glfw3.dll
        )
## IMPORTED SHARED LIBRARY .lib file
set( SHARED_LIB
        ${CMAKE_SOURCE_DIR}/external/${CMAKE_BUILD_TYPE}/glfw3.lib
        )

## SHARED LIBRARY LINKING
## <=====================================>
list(LENGTH SHARED_LIB_NAME  list_len)
math(EXPR LIST_LEN "${list_len} - 1")

if (${LIST_LEN} GREATER_EQUAL 0)
    foreach(ctr RANGE ${LIST_LEN})
        list(GET SHARED_LIB_NAME ${ctr} lib)
        list(GET SHARED_LIB_LOCATION ${ctr} loc)
        list(GET SHARED_LIB ${ctr} filelib)
        add_library(${lib} SHARED IMPORTED)
        set_target_properties(${lib} PROPERTIES
                IMPORTED_LOCATION ${loc}
                IMPORTED_IMPLIB ${filelib}
                )
    endforeach()
    target_link_libraries(${EXEC}
            PUBLIC
            ${SHARED_LIB_NAME}
            )
endif ()
## <=====================================>

## IMPORTED STATIC LIBRARY NAME
set( STATIC_LIB_NAME
        )

## IMPORTED STATIC LIBRARY .lib file
set( STATIC_LIB
        )

## STATIC LIBRARY LINKING
## <=====================================>
list(LENGTH STATIC_LIB_NAME  list_len)
math(EXPR LIST_LEN "${list_len} - 1")

if (${LIST_LEN} GREATER_EQUAL 0)
    foreach(ctr RANGE ${LIST_LEN})
        list(GET STATIC_LIB_NAME ${ctr} lib)
        list(GET STATIC_LIB ${ctr} filelib)
        add_library(${lib} STATIC IMPORTED)
        set_target_properties(${lib} PROPERTIES
                IMPORTED_LOCATION ${filelib}
                )
    endforeach()
    target_link_libraries(${EXEC}
            PUBLIC
            ${STATIC_LIB_NAME}
            )
endif ()
## <=====================================>