/*
Copyright (c) 2021 Filip Anton (filipworks)
Created for Goblin Engine github.com/goblinengine
Initial implementation based on https://github.com/RodZill4/godot-music

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef AUDIO_STREAM_MIDI_H
#define AUDIO_STREAM_MIDI_H

#include "thirdparty/tsf/tml.h"
#include "thirdparty/tsf/tsf.h"

#include "core/io/resource_importer.h"
#include "core/io/file_access.h"

#include "scene/audio/audio_stream_player.h"
#include "servers/audio/effects/audio_stream_generator.h"

#include "midi_file.h"

class AudioStreamMidi;

class AudioStreamPlaybackMidi : public AudioStreamPlayback {
	GDCLASS(AudioStreamPlaybackMidi, AudioStreamPlayback);

	friend class AudioStreamMidi;
	
};


class AudioStreamMidi : public AudioStream {
	GDCLASS(AudioStreamMidi, AudioStream);
	OBJ_SAVE_TYPE(AudioStream) //children are all saved as AudioStream, so they can be exchanged
	RES_BASE_EXTENSION("mdf");
private:
	Ref<AudioStreamPlayback> playback;
	Ref<SoundfontFile> soundfont;
	tsf *mTsf = nullptr;
	Ref<MidiFile> midi;
	tml_message *mTml = nullptr;
	tml_message *midiCurrent = nullptr;
	double midiTime;
	float midi_speed = 1.0;
	bool looping = true;

protected:
	static void _bind_methods();
	void _notification(int p_what);

	

	PackedVector2Array get_buffer(int inSize);

public:
	void set_soundfont(Ref<SoundfontFile> sf);
	Ref<SoundfontFile> get_soundfont() const;

	void set_midi(Ref<MidiFile> mid);
	Ref<MidiFile> get_midi() const;

	void set_midi_speed(float p_speed);
	float get_midi_speed();

	void set_looping(bool p_looping);
	bool is_looping();

	PackedStringArray get_preset_names() const;
	int get_preset_index(int inBank, int inPresetNumber);

	void set_output(int inSampleRate, float inGainDb);

	void note_on(int inPresetIndex, int inKey, float inVelocity);
	void note_off(int inPresetIndex, int inKey);
	void note_off_all();

	void channel_set_preset_index(int inChannel, int inPresetIndex);
	int channel_set_preset_number(int inChannel, int inPresetNumber, int inDrums);
	void channel_set_bank(int inChannel, int inBank);
	int channel_set_bank_preset(int inChannel, int inBank, int inPresetNumber);
	void channel_set_pan(int inChannel, float inPan);
	void channel_set_volume(int inChannel, float inVolume);
	void channel_set_pitchwheel(int inChannel, int inPitchWheel);
	void channel_set_pitchrange(int inChannel, float inPitchRange);
	void channel_set_tuning(int inChannel, float inTuning);
	void channel_note_on(int inChannel, int inKey, float inVelocity);
	void channel_note_off(int inChannel, int inKey);
	void channel_note_off_all(int inChannel); // End with sustain and release.
	void channel_sounds_off_all(int inChannel); // End immediately.
	void channel_midi_control(int inChannel, int inController, int inValue);
	int channel_get_preset_index(int inChannel);
	int channel_get_preset_bank(int inChannel);
	int channel_get_preset_number(int inChannel);
	float channel_get_pan(int inChannel);
	float channel_get_volume(int inChannel);
	int channel_get_pitchwheel(int inChannel);
	float channel_get_pitchrange(int inChannel);
	float channel_get_tuning(int inChannel);

	~MidiPlayer();
};

#endif // AUDIO_STREAM_MIDI_H
