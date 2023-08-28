#include "midi_file.h"



void MidiFile::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_data", "data"), &MidiFile::set_data);
	ClassDB::bind_method(D_METHOD("get_data"), &MidiFile::get_data);

	ADD_PROPERTY(PropertyInfo(Variant::PACKED_BYTE_ARRAY, "data", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NO_EDITOR), "set_data", "get_data");
}

PackedByteArray MidiFile::get_data() const {
	return data;
}

void MidiFile::set_data(const Vector<uint8_t> &dataIn) {
	int in_data_len = dataIn.size();
	const uint8_t *src_datar = dataIn.ptr();

	data.clear();
	data.resize(in_data_len);
	memcpy(data.ptrw(), src_datar, in_data_len);
}

MidiFile::~MidiFile() {
	data.clear();
}

void SoundfontFile::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_data", "data"), &SoundfontFile::set_data);
	ClassDB::bind_method(D_METHOD("get_data"), &SoundfontFile::get_data);

	ADD_PROPERTY(PropertyInfo(Variant::PACKED_BYTE_ARRAY, "data", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NO_EDITOR), "set_data", "get_data");
}

PackedByteArray SoundfontFile::get_data() const {
	return data;
}

void SoundfontFile::set_data(const Vector<uint8_t> &dataIn) {
	int in_data_len = dataIn.size();
	const uint8_t *src_datar = dataIn.ptr();

	data.clear();
	data.resize(in_data_len);
	memcpy(data.ptrw(), src_datar, in_data_len);
}

SoundfontFile::~SoundfontFile() {
	data.clear();
}