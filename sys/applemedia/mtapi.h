/*
 * Copyright (C) 2010 Ole André Vadla Ravnås <oravnas@cisco.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GST_MT_API_H__
#define __GST_MT_API_H__

#include "cmapi.h"

G_BEGIN_DECLS

typedef struct _GstMTApi GstMTApi;
typedef struct _GstMTApiClass GstMTApiClass;

typedef struct _FigCaptureDevice * FigCaptureDeviceRef;
typedef struct _FigCaptureStream * FigCaptureStreamRef;
typedef struct _FigCaptureStreamIface FigCaptureStreamIface;

struct _FigCaptureStreamIface
{
  gsize unk;
  FigStatus (* Start) (FigCaptureStreamRef stream);
  FigStatus (* Stop) (FigCaptureStreamRef stream);
};

struct _GstMTApi
{
  GstDynApi parent;

  FigBaseObjectRef (* FigCaptureDeviceGetFigBaseObject)
    (FigCaptureDeviceRef device);
  FigBaseObjectRef (* FigCaptureStreamGetFigBaseObject)
    (FigCaptureStreamRef stream);

  CFStringRef * kFigCaptureDeviceProperty_ImagerFormatDescription;
  CFStringRef * kFigCaptureDeviceProperty_ImagerFrameRate;
  CFStringRef * kFigCaptureDeviceProperty_ImagerMinimumFrameRate;
  CFStringRef * kFigCaptureDeviceProperty_ImagerSupportedFormatsArray;
  CFStringRef * kFigCaptureStreamProperty_BufferQueue;
  CFStringRef * kFigImagerSupportedFormat_FormatDescription;
  CFStringRef * kFigImagerSupportedFormat_IsBinned;
  CFStringRef * kFigImagerSupportedFormat_MaxFrameRate;
  CFStringRef * kFigImagerSupportedFormat_ScaleFactor;
};

struct _GstMTApiClass
{
  GstDynApiClass parent_class;
};

GType gst_mt_api_get_type (void);

GstMTApi * gst_mt_api_obtain (GError ** error);

G_END_DECLS

#endif
