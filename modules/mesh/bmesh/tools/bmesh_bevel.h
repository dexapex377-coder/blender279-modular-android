/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor(s): Campbell Barton
 *
 * ***** END GPL LICENSE BLOCK *****
 */

#ifndef __BMESH_BEVEL_H__
#define __BMESH_BEVEL_H__

/** \file blender/bmesh/tools/bmesh_bevel.h
 *  \ingroup bmesh
 */

typedef enum BevelType {
    BEVEL_TYPE_OFFSET = 0,
    BEVEL_TYPE_WIDTH = 1,
    BEVEL_TYPE_DEPTH = 2,
    BEVEL_TYPE_PERCENT = 3,
} BevelType;

typedef enum BevelSegments {
    BEVEL_SEGMENTS_MAX = 100,
} BevelSegments;

typedef enum BevelProfileType {
    BEVEL_PROFILE_SUPER_ELLIPSE = 0,
    BEVEL_PROFILE_CUSTOM = 1,
} BevelProfileType;

typedef enum BevelVertexGroupMode {
    BEVEL_VGROUP_NONE = 0,
    BEVEL_VGROUP_WEIGHT = 1,
    BEVEL_VGROUP_INVERT = 2,
} BevelVertexGroupMode;

typedef enum BevelHardenNormalsMode {
    BEVEL_HARDEN_NORMALS_NONE = 0,
    BEVEL_HARDEN_NORMALS_APPLY = 1,
    BEVEL_HARDEN_NORMALS_BOTH = 2,
} BevelHardenNormalsMode;

void BM_mesh_bevel(
        BMesh *bm,
        const int segments, const float width,
        const BevelType bevel_type,
        const float profile, const bool clamp_overlap,
        const bool loop_slide, const bool mark,
        const bool harden_normals,
        const int vertex_group, const BevelVertexGroupMode vgroup_mode,
        const float miter_outer, const float miter_inner,
        const float spread, const float custom_profile[]);

void BM_mesh_bevels_from_edges(
        BMesh *bm,
        const bool do_mark,
        const BevelType bevel_type,
        const int segments, const float width,
        const float profile, const bool clamp_overlap,
        const bool loop_slide,
        const bool harden_normals,
        const int vertex_group, const BevelVertexGroupMode vgroup_mode,
        const float miter_outer, const float miter_inner,
        const float spread, const float custom_profile[]);

void BM_mesh_bevels_from_verts(
        BMesh *bm,
        const bool do_mark,
        const BevelType bevel_type,
        const int segments, const float width,
        const float profile, const bool clamp_overlap,
        const bool loop_slide,
        const bool harden_normals,
        const int vertex_group, const BevelVertexGroupMode vgroup_mode,
        const float miter_outer, const float miter_inner,
        const float spread, const float custom_profile[]);

#endif /* __BMESH_BEVEL_H__ */