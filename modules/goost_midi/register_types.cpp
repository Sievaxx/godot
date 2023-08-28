/**************************************************************************/
/*  register_types.cpp                                                    */
/**************************************************************************/

#include "register_types.h"

#include "audio_stream_midi.h"

#include "resource_importer_midi.h"

#ifdef TOOLS_ENABLED
#include "core/config/engine.h"
#endif


void initialize_goost_midi_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

#ifdef TOOLS_ENABLED
	if (Engine::get_singleton()->is_editor_hint()) {
		Ref<ResourceImporterMidiFile> midifile;
		midifile.instantiate();
		Ref<ResourceImporterSoundfontFile> soundfontfile;
		soundfontfile.instantiate();
		ResourceFormatImporter::get_singleton()->add_importer(midifile);
		ResourceFormatImporter::get_singleton()->add_importer(soundfontfile);
	}
#endif
	GDREGISTER_CLASS(MidiFile);
	GDREGISTER_CLASS(SoundfontFile);
	GDREGISTER_CLASS(MidiPlayer);
}

void uninitialize_goost_midi_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}