#ifndef RESOURCE_IMPORTER_MIDI_H
#define RESOURCE_IMPORTER_MIDI_H

#include "core/io/resource_importer.h"
#include "core/io/file_access.h"
#include "core/io/resource.h"
#include "midi_file.h"

class ResourceImporterSoundfontFile : public ResourceImporter {
	GDCLASS(ResourceImporterSoundfontFile, ResourceImporter);

	public:
	virtual String get_importer_name() const override;
	virtual String get_visible_name() const override;
	virtual void get_recognized_extensions(List<String> *p_extensions) const override;
	virtual String get_save_extension() const override;
	virtual String get_resource_type() const override;

	virtual int get_preset_count() const override;
	virtual String get_preset_name(int p_idx) const override;

	virtual void get_import_options(const String &p_path, List<ImportOption> *r_options, int p_preset = 0) const override;
	virtual bool get_option_visibility(const String &p_path, const String &p_option, const HashMap<StringName, Variant> &p_options) const override;

#ifdef TOOLS_ENABLED
	virtual bool has_advanced_options() const override;
	virtual void show_advanced_options(const String &p_path) override;
#endif
	static Ref<SoundfontFile> import_soundfont(const String &p_path);

	virtual Error import(const String &p_source_file, const String &p_save_path, const HashMap<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files = nullptr, Variant *r_metadata = nullptr);
	ResourceImporterSoundfontFile();

};

class ResourceImporterMidiFile : public ResourceImporter {
	GDCLASS(ResourceImporterMidiFile, ResourceImporter);

public:
	virtual String get_importer_name() const override;
	virtual String get_visible_name() const override;
	virtual void get_recognized_extensions(List<String> *p_extensions) const override;
	virtual String get_save_extension() const override;
	virtual String get_resource_type() const override;

	virtual int get_preset_count() const override;
	virtual String get_preset_name(int p_idx) const override;

	virtual void get_import_options(const String &p_path, List<ImportOption> *r_options, int p_preset = 0) const override;
	virtual bool get_option_visibility(const String &p_path, const String &p_option, const HashMap<StringName, Variant> &p_options) const override;

#ifdef TOOLS_ENABLED
	virtual bool has_advanced_options() const override;
	virtual void show_advanced_options(const String &p_path) override;
#endif
	static Ref<MidiFile> import_midi(const String &p_path);

	virtual Error import(const String &p_source_file, const String &p_save_path, const HashMap<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files = nullptr, Variant *r_metadata = nullptr);
	ResourceImporterMidiFile();
};

#endif // RESOURCE_IMPORTER_MIDI_H