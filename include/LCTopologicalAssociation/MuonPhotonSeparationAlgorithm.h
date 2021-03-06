/**
 *  @file   LCContent/include/LCTopologicalAssociation/MipPhotonSeparationAlgorithm.h
 * 
 *  @brief  Header file for the mip-photon separation algorithm class.
 * 
 *  $Log: $
 */
#ifndef LC_MUON_PHOTON_SEPARATION_ALGORITHM_H
#define LC_MUON_PHOTON_SEPARATION_ALGORITHM_H 1

#include "LCTopologicalAssociation/MipPhotonSeparationAlgorithm.h"

namespace lc_content
{

/**
 *  @brief  MuonPhotonSeparationAlgorithm class
 */
class MuonPhotonSeparationAlgorithm : public MipPhotonSeparationAlgorithm
{
public:
    /**
     *  @brief Default constructor
     */
    MuonPhotonSeparationAlgorithm();

private:
    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

    pandora::StatusCode PerformFragmentation(const pandora::Cluster *const pOriginalCluster, const pandora::Track *const pTrack,
        unsigned int showerStartLayer, unsigned int showerEndLayer) const;

    pandora::StatusCode MakeClusterFragments(const unsigned int showerStartLayer, const unsigned int showerEndLayer,
        const pandora::Cluster *const pOriginalCluster, const pandora::Cluster *&pMipCluster, const pandora::Cluster *&pPhotonCluster) const;

    float           m_highEnergyMuonCut;            ///< Cut for muon to be considered high energy
    unsigned int    m_nTransitionLayers;            ///< Number of transition layers, treated more flexibly, between shower and mip-region
};

} // namespace lc_content

#endif // #ifndef LC_MUON_PHOTON_SEPARATION_ALGORITHM_H
