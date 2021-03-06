// OKIM6295 sound chip emulator interface

// Game_Music_Emu $vers
#ifndef OKIM6295_EMU_H
#define OKIM6295_EMU_H

class Okim6295_Emu  {
	void* chip;
public:
	Okim6295_Emu();
	~Okim6295_Emu();
	
	// Sets output sample rate and chip clock rates, in Hz. Returns non-zero
	// if error.
	int set_rate( int clock_rate );
	
	// Resets to power-up state
	void reset();
	
	// Mutes voice n if bit n (1 << n) of mask is set
	enum { channel_count = 4 };
	void mute_voices( int mask );
	
	// Writes data to addr
	void write( int addr, int data );

	// Scales ROM size, then writes length bytes from data at start offset
	void write_rom( int size, int start, int length, void * data );
	
	// Runs and writes pair_count*2 samples to output
	typedef short sample_t;
	enum { out_chan_count = 2 }; // stereo
	void run( int pair_count, sample_t* out );
};

#endif
