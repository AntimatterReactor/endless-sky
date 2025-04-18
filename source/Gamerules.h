/* Gamerules.h
Copyright (c) 2022 by Amazinite

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

class DataNode;



// Gamerules contains a list of constants and booleans that define game behavior,
// for example, the spawnrate of person ships or whether universal ramscoops are active.
class Gamerules {
public:
	// Defines which disabled fighters can dodge stray projectiles.
	enum class FighterDodgePolicy
	{
		ALL, NONE, ONLY_PLAYER
	};


public:
	Gamerules() = default;

	// Load a gamerules node.
	void Load(const DataNode &node);

	bool UniversalRamscoopActive() const;
	int PersonSpawnPeriod() const;
	int NoPersonSpawnWeight() const;
	int NPCMaxMiningTime() const;
	double UniversalFrugalThreshold() const;
	double DepreciationMin() const;
	double DepreciationDaily() const;
	int DepreciationGracePeriod() const;
	int DepreciationMaxAge() const;
	FighterDodgePolicy FightersHitWhenDisabled() const;
	double SystemDepartureMin() const;
	double SystemArrivalMin() const;
	double FleetMultiplier() const;


private:
	bool universalRamscoop = true;
	int personSpawnPeriod = 36000;
	int noPersonSpawnWeight = 1000;
	int npcMaxMiningTime = 3600;
	double universalFrugalThreshold = .75;
	double depreciationMin = 0.25;
	double depreciationDaily = 0.997;
	int depreciationGracePeriod = 7;
	int depreciationMaxAge = 1000;
	FighterDodgePolicy fighterHitPolicy = FighterDodgePolicy::ALL;
	double systemDepartureMin = 0.;
	double systemArrivalMin = 0.;
	double fleetMultiplier = 1.;
};
