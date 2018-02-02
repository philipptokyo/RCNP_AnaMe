 
#ifndef main_h
#define main_h

#include "LibPerso.h"

using std::vector;

struct _FERA_RAW{
  UShort_t GR_FERA_ADC[64];
  UShort_t LAS_FERA_ADC[64];
  UShort_t GR_FERA_TDC[64];
  UShort_t LAS_FERA_TDC[64];
  
  void Clear(){
    memset(GR_FERA_ADC, 0, sizeof(GR_FERA_ADC));
    memset(LAS_FERA_ADC, 0, sizeof(LAS_FERA_ADC));
    memset(GR_FERA_TDC, 0, sizeof(GR_FERA_TDC));
    memset(LAS_FERA_TDC, 0, sizeof(LAS_FERA_TDC));
  }
};

struct _EVENT{
  Bool_t EVENT_GR;
  Bool_t EVENT_LAS;
  Bool_t EVENT_COIN;
};

struct _GR{
  UShort_t GR_ADC[6];
  UShort_t GR_MADC[3];
  UShort_t GR_TDC[6];
  UShort_t GR_RF[3];
  UShort_t GR_TLAS;
  UShort_t R_TDIFF[3];
};

struct _GF{
  UShort_t GF_ADC_XU[8];
  UShort_t GF_ADC_XD[8];
  UShort_t GF_ADC_YL[5];
  UShort_t GF_ADC_YR[5];
  UShort_t GF_MADC_X[8];
  UShort_t GF_MADC_Y[5];
  UShort_t GF_TDC_XU[8];
  UShort_t GF_TDC_XD[8];
  UShort_t GF_TDC_YL[5];
  UShort_t GF_TDC_YR[5];
  UShort_t GF_TDIFF_X[8];
  UShort_t GF_TDIFF_Y[5];
};

struct _LAS{
  UShort_t LAS_ADC[12];
  UShort_t LAS_MADC[6];
  UShort_t LAS_TDC[12];
  UShort_t LAS_RF[3];
  UShort_t LAS_TDIFF[6];
};

struct _V1190_RAW{
  Float_t TDC;
  UShort_t Geo;
  UShort_t Channel;
  Short_t Wire;
};


vector<UShort_t> RegionIDs;

vector<UShort_t> IPR;

vector<UShort_t> GR_ADC_OLD;
vector<UInt_t> GR_V830;

vector<UShort_t> FERA_Type;
vector<UShort_t> FERA_Ch;
vector<UShort_t> FERA_Mid;

_FERA_RAW FERA_RAW;
_EVENT EVENT;
_GR GR;
_GF GF;
_LAS LAS;
UShort_t BLP_ADC[8];

vector<UShort_t> GR_WIRE_X1;
vector<UShort_t> GR_WIRE_U1;
vector<UShort_t> GR_WIRE_X2;
vector<UShort_t> GR_WIRE_U2;
vector<Float_t> GR_TDC_X1;
vector<Float_t> GR_TDC_U1;
vector<Float_t> GR_TDC_X2;
vector<Float_t> GR_TDC_U2;

vector<UShort_t> LAS_WIRE_X1;
vector<UShort_t> LAS_WIRE_U1;
vector<UShort_t> LAS_WIRE_V1;
vector<UShort_t> LAS_WIRE_X2;
vector<UShort_t> LAS_WIRE_U2;
vector<UShort_t> LAS_WIRE_V2;
vector<Float_t> LAS_TDC_X1;
vector<Float_t> LAS_TDC_U1;
vector<Float_t> LAS_TDC_V1;
vector<Float_t> LAS_TDC_X2;
vector<Float_t> LAS_TDC_U2;
vector<Float_t> LAS_TDC_V2;

vector<_V1190_RAW> V1190_RAW;
Int_t V1190_QTC[16][2];

vector<UInt_t> Scaler;
UInt_t Time;

UShort_t ChkSum;




Int_t main(Int_t argc, char **argv);

#endif
