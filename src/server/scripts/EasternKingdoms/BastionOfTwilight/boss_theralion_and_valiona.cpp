/*
 * Copyright (C) 2011-2013 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2010-2011 MigCore <http://wow-mig.ru/>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#include "ScriptPCH.h"
#include "bastion_of_twilight.h"

enum Spells
{
    SPELL_BERSERK                   = 47008,
	SPELL_TWILIGHT_SHIFT1           = 86360,
	SPELL_TWILIGHT_SHIFT2           = 93051,
	//Theralion
	SPELL_DAZZLING_DESTRUCTION      = 86408,
	SPELL_ENGULFING_MAGIC           = 86622,
	SPELL_FABULOUS_FLAMES           = 86505,
	SPELL_TWILIGHT_BLAST            = 86369,
	//Valiona
	SPELL_BLACKOUT                  = 86788,
    SPELL_DEEP_BREATH               = 86059,
    SPELL_DEVOURING_FLAMES          = 86840,
    SPELL_TWILIGHT_METEORITE 	    = 86013
};

class boss_valiona : public CreatureScript
{
public:
    boss_valiona() : CreatureScript("boss_valiona") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_valionaAI (creature);
    }

    struct boss_valionaAI : public ScriptedAI
    {
        boss_valionaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            instance->SetData(DATA_THERALION_ANA_VALIONA, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            instance->SetData(DATA_THERALION_ANA_VALIONA, IN_PROGRESS);
        }

        void JustDied(Unit* /*Killer*/)
        {
            instance->SetData(DATA_THERALION_ANA_VALIONA, DONE);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_theralion_and_valiona()
{
    new boss_valiona();
}
