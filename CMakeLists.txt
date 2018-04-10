
cmake_minimum_required(VERSION 3.4.1)

set(VEROVIO_DIR ./)
set(VEROVIO_INCLUDE ${VEROVIO_DIR}/include/)
set(LIBMEI_DIR ${VEROVIO_DIR}/libmei/)

set(
  VEROVIO_INCLUDES
    ${VEROVIO_INCLUDE}/hum
    ${VEROVIO_INCLUDE}/json
    ${VEROVIO_INCLUDE}/midi
    ${VEROVIO_INCLUDE}/pugi
    ${VEROVIO_INCLUDE}/utf8
    ${VEROVIO_INCLUDE}/vrv
    ${VEROVIO_DIR}/libmei
)

include_directories(
  ${VEROVIO_INCLUDES}
)

file(GLOB VRV_SRC "${VEROVIO_DIR}/src/*.cpp")
file(GLOB HUM_SRC "${VEROVIO_DIR}/src/hum/*.cpp")
file(GLOB MIDI_SRC "${VEROVIO_DIR}/src/midi/*.cpp")
file(GLOB PUGI_SRC "${VEROVIO_DIR}/src/pugi/*.cpp")

set(LIBMEI_SRC
    ${LIBMEI_DIR}/attconverter.cpp
    ${LIBMEI_DIR}/atts_cmn.cpp
    ${LIBMEI_DIR}/atts_cmnornaments.cpp
    ${LIBMEI_DIR}/atts_critapp.cpp
    ${LIBMEI_DIR}/atts_externalsymbols.cpp
    ${LIBMEI_DIR}/atts_mei.cpp
    ${LIBMEI_DIR}/atts_mensural.cpp
    ${LIBMEI_DIR}/atts_midi.cpp
    ${LIBMEI_DIR}/atts_pagebased.cpp
    ${LIBMEI_DIR}/atts_shared.cpp
)

set(
    VEROVIO_SRC
    ${VRV_SRC}
    ${HUM_SRC}
    ${MIDI_SRC}
    ${PUGI_SRC}
    ${LIBMEI_SRC}
    ${VEROVIO_DIR}/src/json/jsonxx.cc
)

add_library(Verovio STATIC ${VEROVIO_SRC})

target_include_directories(Verovio PUBLIC ${VEROVIO_INCLUDES})
