#ifndef MIDI_FILE_H
#define MIDI_FILE_H

#include "core/io/resource.h"

class MidiFile : public Resource {
	GDCLASS(MidiFile, Resource);
    OBJ_SAVE_TYPE(Resource);

	PackedByteArray data;
	uint32_t data_len = 0;

protected:
	static void _bind_methods();

public:
	void set_data(const Vector<uint8_t> &p_data);
	Vector<uint8_t> get_data() const;

	~MidiFile();
};

class SoundfontFile : public Resource {
	GDCLASS(SoundfontFile, Resource);
    OBJ_SAVE_TYPE(Resource);

	PackedByteArray data;
	uint32_t data_len = 0;

protected:
	static void _bind_methods();

public:
	void set_data(const Vector<uint8_t> &p_data);
	Vector<uint8_t> get_data() const;

	~SoundfontFile();
};

#endif // MIDI_FILE_H