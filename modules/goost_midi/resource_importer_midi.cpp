
#include "resource_importer_midi.h"


/* RESOURCE IMPORTER MIDI FILE */
String ResourceImporterMidiFile::get_visible_name() const {
	return "midifile"; 
}

String ResourceImporterMidiFile::get_importer_name() const {
	return "MidiFile";
}

void ResourceImporterMidiFile::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("mid");
	p_extensions->push_back("midi");
}

String ResourceImporterMidiFile::get_save_extension() const {
	return "mdf";
}

String ResourceImporterMidiFile::get_resource_type() const {
	return "MidiFile";
}

int ResourceImporterMidiFile::get_preset_count() const {
	return 0;
}

String ResourceImporterMidiFile::get_preset_name(int p_idx) const {
	return String();
}

void ResourceImporterMidiFile::get_import_options(const String &p_path, List<ImportOption> *r_options, int p_preset) const {
}

bool ResourceImporterMidiFile::get_option_visibility(const String &p_path, const String &p_option, const HashMap<StringName, Variant> &p_options) const {
	return true;
}

#ifdef TOOLS_ENABLED
bool ResourceImporterMidiFile::has_advanced_options() const {
	return false;
}
void ResourceImporterMidiFile::show_advanced_options(const String &p_path) {
}
#endif

ResourceImporterMidiFile::ResourceImporterMidiFile() {
}

Ref<MidiFile> ResourceImporterMidiFile::import_midi(const String &p_path) {
	Ref<FileAccess> f = FileAccess::open(p_path, FileAccess::READ);
	ERR_FAIL_COND_V(f.is_null(), Ref<MidiFile>());

	uint64_t len = f->get_length();

	Vector<uint8_t> data;
	data.resize(len);
	uint8_t *w = data.ptrw();

	f->get_buffer(w, len);

	Ref<MidiFile> mdf;
	mdf.instantiate();

	mdf->set_data(data);
	ERR_FAIL_COND_V(!mdf->get_data().size(), Ref<MidiFile>());

	return mdf;
}

Error ResourceImporterMidiFile::import(const String &p_source_file, const String &p_save_path, const HashMap<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata) {
	Ref<MidiFile> mdf = import_midi(p_source_file);
	if (mdf.is_null()) {
		return ERR_CANT_OPEN;
	}

	return ResourceSaver::save(mdf, p_save_path + ".mdf");
}

/* RESOURCE IMPORTER SOUNDFONT FILE */
String ResourceImporterSoundfontFile::get_visible_name() const {
	return "soundfontfile"; 
}

String ResourceImporterSoundfontFile::get_importer_name() const {
	return "SoundfontFile";
}

void ResourceImporterSoundfontFile::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("sf2");
}

String ResourceImporterSoundfontFile::get_save_extension() const {
	return "mds";
}

String ResourceImporterSoundfontFile::get_resource_type() const {
	return "SoundfontFile";
}

int ResourceImporterSoundfontFile::get_preset_count() const {
	return 0;
}

String ResourceImporterSoundfontFile::get_preset_name(int p_idx) const {
	return String();
}

void ResourceImporterSoundfontFile::get_import_options(const String &p_path, List<ImportOption> *r_options, int p_preset) const {
}

bool ResourceImporterSoundfontFile::get_option_visibility(const String &p_path, const String &p_option, const HashMap<StringName, Variant> &p_options) const {
	return true;
}

#ifdef TOOLS_ENABLED
bool ResourceImporterSoundfontFile::has_advanced_options() const {
	return false;
}
void ResourceImporterSoundfontFile::show_advanced_options(const String &p_path) {
}
#endif

ResourceImporterSoundfontFile::ResourceImporterSoundfontFile() {
}

Ref<SoundfontFile> ResourceImporterSoundfontFile::import_soundfont(const String &p_path) {
	Ref<FileAccess> f = FileAccess::open(p_path, FileAccess::READ);
	ERR_FAIL_COND_V(f.is_null(), Ref<SoundfontFile>());

	uint64_t len = f->get_length();

	Vector<uint8_t> data;
	data.resize(len);
	uint8_t *w = data.ptrw();

	f->get_buffer(w, len);

	Ref<SoundfontFile> sf2;
	sf2.instantiate();

	sf2->set_data(data);
	ERR_FAIL_COND_V(!sf2->get_data().size(), Ref<SoundfontFile>());

	return sf2;
}

Error ResourceImporterSoundfontFile::import(const String &p_source_file, const String &p_save_path, const HashMap<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata) {
	Ref<SoundfontFile> sf2 = import_soundfont(p_source_file);
	if (sf2.is_null()) {
		return ERR_CANT_OPEN;
	}

	return ResourceSaver::save(sf2, p_save_path + ".mdsf");
}

