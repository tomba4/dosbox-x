/* FluidSynth - A Software Synthesizer
 *
 * Copyright (C) 2003  Peter Hanappe and others.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License
 * as published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */


#ifndef _FLUID_REV_H
#define _FLUID_REV_H

#include "../utils/fluidsynth_priv.h"

typedef struct _fluid_revmodel_t fluid_revmodel_t;


/** Flags for fluid_revmodel_set() */
typedef enum
{
  FLUID_REVMODEL_SET_ROOMSIZE       = 1 << 0,
  FLUID_REVMODEL_SET_DAMPING        = 1 << 1,
  FLUID_REVMODEL_SET_WIDTH          = 1 << 2,
  FLUID_REVMODEL_SET_LEVEL          = 1 << 3
} fluid_revmodel_set_t;

/** Value for fluid_revmodel_set() which sets all reverb parameters. */
#define FLUID_REVMODEL_SET_ALL      0x0F

/*
 * reverb preset
 */
typedef struct _fluid_revmodel_presets_t {
  char* name;
  fluid_real_t roomsize;
  fluid_real_t damp;
  fluid_real_t width;
  fluid_real_t level;
} fluid_revmodel_presets_t;


/*
 * reverb
 */
fluid_revmodel_t* new_fluid_revmodel(fluid_real_t sample_rate);
void delete_fluid_revmodel(fluid_revmodel_t* rev);

void fluid_revmodel_processmix(fluid_revmodel_t* rev, fluid_real_t *in,
			      fluid_real_t *left_out, fluid_real_t *right_out);

void fluid_revmodel_processreplace(fluid_revmodel_t* rev, fluid_real_t *in,
				  fluid_real_t *left_out, fluid_real_t *right_out);

void fluid_revmodel_reset(fluid_revmodel_t* rev);

void fluid_revmodel_set(fluid_revmodel_t* rev, int set, float roomsize,
                        float damping, float width, float level);

void fluid_revmodel_samplerate_change(fluid_revmodel_t* rev, fluid_real_t sample_rate);

#endif /* _FLUID_REV_H */
