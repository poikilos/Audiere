SUBDIRS = mpaudec

lib_LTLIBRARIES = libaudiere.la
include_HEADERS = audiere.h

if HAVE_FLAC
FLAC_SOURCES = input_flac.cpp input_flac.h
else
FLAC_DIST    = input_flac.cpp input_flac.h
endif

if HAVE_DUMB
DUMB_SOURCES = input_mod.cpp input_mod.h
else
DUMB_DIST    = input_mod.cpp input_mod.h
endif

if HAVE_OGG
OGG_SOURCES = input_ogg.cpp input_ogg.h
else
OGG_DIST    = input_ogg.cpp input_ogg.h
endif

if HAVE_SPEEX
SPEEX_SOURCES = input_speex.cpp input_speex.h speexfile/speexfile.h speexfile/speexfile.cpp
else
SPEEX_DIST    = input_speex.cpp input_speex.h speexfile/speexfile.h speexfile/speexfile.cpp
endif

if HAVE_AL
AL_SOURCES = device_al.cpp device_al.h
else
AL_DIST    = device_al.cpp device_al.h
endif

if HAVE_OSS
OSS_SOURCES = device_oss.cpp device_oss.h
else
OSS_DIST    = device_oss.cpp device_oss.h
endif

if HAVE_SDL
SDL_SOURCES = device_sdl.cpp device_sdl.h
else
SDL_DIST    = device_sdl.cpp device_sdl.h
endif

if HAVE_PULSE
PULSE_SOURCES = device_pulse.cpp device_pulse.h
else
PULSE_DIST    = device_pulse.cpp device_pulse.h
endif

if HAVE_ALSA
ALSA_SOURCES = device_alsa.cpp device_alsa.h
else
ALSA_DIST    = device_alsa.cpp device_alsa.h
endif

if HAVE_PA
PA_SOURCES = device_pa.cpp device_pa.h
else
PA_DIST    = device_pa.cpp device_pa.h
endif

DSOUND_SRC = \
	device_ds.cpp device_ds.h \
	device_ds_buffer.cpp device_ds_buffer.h \
	device_ds_stream.cpp device_ds_stream.h \
	dxguid.cpp

if HAVE_DSOUND
DSOUND_SOURCES = $(DSOUND_SRC)
else
DSOUND_DIST = $(DSOUND_SRC)
endif

if HAVE_WINMM
WINMM_SOURCES = device_mm.cpp device_mm.h
else
WINMM_DIST    = device_mm.cpp device_mm.h
endif

if HAVE_CORE_AUDIO
COREAUDIO_SOURCES = device_coreaudio.cpp device_coreaudio.h
else
COREAUDIO_DIST    = device_coreaudio.cpp device_coreaudio.h
endif

# Automake blows.
# A lot.
if HAVE_LIBCDAUDIO
LIBCDAUDIO_SOURCES  = cd_unix.cpp
WINCDAUDIO_DIST     = cd_win32.cpp
NULLCDAUDIO_DIST    = cd_null.cpp
else
LIBCDAUDIO_DIST     = cd_unix.cpp
if HAVE_WINMM
WINCDAUDIO_SOURCES  = cd_win32.cpp
NULLCDAUDIO_DIST    = cd_null.cpp
else
NULLCDAUDIO_SOURCES = cd_null.cpp
WINCDAUDIO_DIST     = cd_win32.cpp
endif
endif

if HAVE_WINMM
MIDI_SOURCES        = midi_mci.cpp
MIDI_DIST           = midi_null.cpp
else
MIDI_SOURCES        = midi_null.cpp
MIDI_DIST           = midi_mci.cpp
endif

if WIN32
THREADS_SOURCES        = threads_win32.cpp
THREADS_DIST           = threads_posix.cpp
TIMER_SOURCES          = timer_win32.cpp
TIMER_DIST             = timer_posix.cpp
else
THREADS_SOURCES        = threads_posix.cpp
THREADS_DIST           = threads_win32.cpp
TIMER_SOURCES          = timer_posix.cpp
TIMER_DIST             = timer_win32.cpp
endif

EXTRA_DIST = \
	$(LIBCDAUDIO_DIST) $(WINCDAUDIO_DIST) $(NULLCDAUDIO_DIST) \
	$(FLAC_DIST) $(DUMB_DIST) $(OGG_DIST) $(SPEEX_DIST) $(AL_DIST) \
	$(OSS_DIST) $(PULSE_DIST) $(DSOUND_DIST) $(WINMM_DIST) $(MIDI_DIST) $(COREAUDIO_DIST) $(PA_DIST) $(SDL_DIST)

libaudiere_la_SOURCES = \
	$(MIDI_SOURCES) \
	basic_source.cpp \
	basic_source.h \
	$(LIBCDAUDIO_SOURCES) \
	$(WINCDAUDIO_SOURCES) \
	$(NULLCDAUDIO_SOURCES) \
	debug.cpp \
	debug.h \
	default_file.h \
	device.cpp \
	device.h \
	$(DSOUND_SOURCES) \
	device_mixer.cpp \
	device_mixer.h \
	device_null.cpp \
	device_null.h \
	$(AL_SOURCES) \
	$(OSS_SOURCES) \
	$(SDL_SOURCES) \
	$(PULSE_SOURCES) \
	$(ALSA_SOURCES) \
	$(PA_SOURCES) \
	$(WINMM_SOURCES) \
	$(COREAUDIO_SOURCES) \
	dumb_resample.cpp \
	dumb_resample.h \
	file_ansi.cpp \
	input.cpp \
	input_aiff.cpp \
	input_aiff.h \
	$(DUMB_SOURCES) \
	$(FLAC_SOURCES) \
	input_mp3.cpp \
	input_mp3.h \
	$(OGG_SOURCES) \
	$(SPEEX_SOURCES) \
	input_wav.cpp \
	input_wav.h \
	internal.h \
	loop_point_source.cpp \
	mci_device.h \
	memory_file.cpp \
	memory_file.h \
	noise.cpp \
	resampler.cpp \
	resampler.h \
	sample_buffer.cpp \
	sound.cpp \
	sound_effect.cpp \
	square_wave.cpp \
	$(THREADS_SOURCES) \
	threads.h \
	$(TIMER_SOURCES) \
	timer.h \
	tone.cpp \
	types.h \
	utility.cpp \
	utility.h \
	version.cpp

libaudiere_la_LDFLAGS =	-release $(VERSION)
libaudiere_la_LIBADD = mpaudec/libmpaudec.la
