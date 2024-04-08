/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WorldStatePackets_h__
#define WorldStatePackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace WorldState
    {
        class InitWorldStates final : public ServerPacket
        {
        public:
            struct WorldStateInfo
            {
                WorldStateInfo(int32 variableID, int32 value)
                    : VariableID(variableID), Value(value) { }

                bool operator < (const WorldStateInfo& info) const
                {
                    return (VariableID < info.VariableID);
                }

                int32 VariableID;
                int32 Value;
            };

            InitWorldStates();

            WorldPacket const* Write() override;

            int32 AreaID    = 0; ///< ZoneId
            int32 SubareaID = 0; ///< AreaId
            int32 MapID     = 0; ///< MapId

            std::vector<WorldStateInfo> Worldstates;
        };

        class UpdateWorldState final : public ServerPacket
        {
        public:
            UpdateWorldState();

            WorldPacket const* Write() override;

            int32 Value       = 0;
            bool Hidden   = false; ///< @todo: research
            uint32 VariableID = 0;
        };
    }
}

#endif // WorldStatePackets_h__