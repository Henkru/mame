// license:BSD-3-Clause
// copyright-holders: kmg, Fabio Priuli
#ifndef MAME_BUS_NES_MMC1_CLONES_H
#define MAME_BUS_NES_MMC1_CLONES_H

#pragma once

#include "mmc1.h"


// ======================> nes_bmc_jy820845c_device

class nes_bmc_jy820845c_device : public nes_sxrom_device
{
public:
	// construction/destruction
	nes_bmc_jy820845c_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock);

	virtual void write_m(offs_t offset, u8 data) override;
	virtual void write_h(offs_t offset, u8 data) override;

	virtual void pcb_reset() override;

protected:
	// device-level overrides
	virtual void device_start() override;

	virtual void set_prg() override { nes_sxrom_device::set_prg(0x18, 0x07); }
	virtual void set_chr() override { nes_sxrom_device::set_chr(0x18, 0x07); }

private:
	void update_banks();
	u8 m_latch0, m_mode;
};


// ======================> nes_ninjaryu_device

class nes_ninjaryu_device : public nes_sxrom_device
{
public:
	// construction/destruction
	nes_ninjaryu_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock);

	virtual void write_h(offs_t offset, u8 data) override;

protected:
	virtual void set_prg() override { nes_sxrom_device::set_prg(0x00, 0x0f); }
	virtual void set_chr() override { nes_sxrom_device::set_chr(0x00, 0x3f); }
};


// ======================> nes_resetsxrom_device

class nes_resetsxrom_device : public nes_sxrom_device
{
public:
	// construction/destruction
	nes_resetsxrom_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock);

	virtual void pcb_reset() override;

protected:
	// device-level overrides
	virtual void device_start() override;

	virtual void set_prg() override { nes_sxrom_device::set_prg(m_reset_count << 3, 0x07); }
	virtual void set_chr() override { nes_sxrom_device::set_chr(m_reset_count << 5, 0x1f); }

private:
	int m_reset_count;
};


// ======================> nes_txc_22110_device

class nes_txc_22110_device : public nes_sxrom_device
{
public:
	// construction/destruction
	nes_txc_22110_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock);

	virtual void write_l(offs_t offset, u8 data) override;
	virtual void write_h(offs_t offset, u8 data) override;

	virtual void pcb_reset() override;

protected:
	// device-level overrides
	virtual void device_start() override;

	virtual void set_prg() override { nes_sxrom_device::set_prg(0x08, 0x07); }
	virtual void set_chr() override { nes_sxrom_device::set_chr(0x20, 0x1f); }

private:
	void update_banks();
	u8 m_latch0, m_mode;
};


// device type definition
DECLARE_DEVICE_TYPE(NES_BMC_JY820845C, nes_bmc_jy820845c_device)
DECLARE_DEVICE_TYPE(NES_NINJARYU,      nes_ninjaryu_device)
DECLARE_DEVICE_TYPE(NES_RESETSXROM,    nes_resetsxrom_device)
DECLARE_DEVICE_TYPE(NES_TXC_22110,     nes_txc_22110_device)

#endif // MAME_BUS_NES_MMC1_CLONES_H
