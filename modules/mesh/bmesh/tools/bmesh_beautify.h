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

#ifndef __BMESH_BEAUTIFY_H__
#define __BMESH_BEAUTIFY_H__

/** \file blender/bmesh/tools/bmesh_beautify.h
 *  \ingroup bmesh
 */

void BM_mesh_beautify_fill(
        BMesh *bm,
        const bool use_face_step, const int face_step,
        const float angle_limit,
        const bool preserve_orientation);

void BM_mesh_beautify(
        BMesh *bm,
        const float angle_limit,
        const bool use_face_step, const int face_step);

#endif /* __BMESH_BEAUTIFY_H__ */