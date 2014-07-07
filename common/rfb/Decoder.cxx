/* Copyright (C) 2002-2005 RealVNC Ltd.  All Rights Reserved.
 * Copyright 2014 Pierre Ossman for Cendio AB
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 * USA.
 */
#include <stdio.h>
#include <rfb/encodings.h>
#include <rfb/Decoder.h>
#include <rfb/RawDecoder.h>
#include <rfb/RREDecoder.h>
#include <rfb/HextileDecoder.h>
#include <rfb/ZRLEDecoder.h>
#include <rfb/TightDecoder.h>

using namespace rfb;

Decoder::~Decoder()
{
}

bool Decoder::supported(int encoding)
{
  switch (encoding) {
  case encodingRaw:
  case encodingRRE:
  case encodingHextile:
  case encodingZRLE:
  case encodingTight:
    return true;
  default:
    return false;
  }
}

Decoder* Decoder::createDecoder(int encoding, CMsgReader* reader)
{
  switch (encoding) {
  case encodingRaw:
    return new RawDecoder(reader);
  case encodingRRE:
    return new RREDecoder(reader);
  case encodingHextile:
    return new HextileDecoder(reader);
  case encodingZRLE:
    return new ZRLEDecoder(reader);
  case encodingTight:
    return new TightDecoder(reader);
  default:
    return NULL;
  }
}
