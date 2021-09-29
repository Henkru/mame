// license:BSD-3-Clause
// copyright-holders:
/***********************************************************************************************************************************


************************************************************************************************************************************/

#include "emu.h"
#include "cpu/i86/i86.h"
#include "machine/i8251.h"

class cubic_state : public driver_device
{
public:
	cubic_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag)
	{ }

	void cubic(machine_config &config);

private:
	void io_map(address_map &map);
	void mem_map(address_map &map);
};

void cubic_state::mem_map(address_map &map)
{
	map(0x00000, 0xf3fff).ram();
	map(0xfc000, 0xfffff).rom().region("roms", 0);
}

void cubic_state::io_map(address_map &map)
{
	//map(0x3000, 0x3001).rw("uart1", FUNC(i8251_device::read), FUNC(i8251_device::write));
}

static INPUT_PORTS_START( cubic )
INPUT_PORTS_END

void cubic_state::cubic(machine_config &config)
{
	i8088_cpu_device &maincpu(I8088(config, "maincpu", XTAL(12'000'000)/3));  // no idea of clock
	maincpu.set_addrmap(AS_PROGRAM, &cubic_state::mem_map);
	maincpu.set_addrmap(AS_IO, &cubic_state::io_map);

	//I8251(config, "uart1", 0);
}

ROM_START( cubic )
	ROM_REGION( 0x4000, "roms", 0 )
	ROM_LOAD( "cubic.bin", 0x0000, 0x4000, CRC(10b93e38) SHA1(0b1a23d384bfde4cd27c482f667eedd94f8f2406) )
ROM_END

COMP( 2021, cubic, 0, 0, cubic, cubic, cubic_state, empty_init, "Cubic", "Cubic 8088", MACHINE_IS_SKELETON )
