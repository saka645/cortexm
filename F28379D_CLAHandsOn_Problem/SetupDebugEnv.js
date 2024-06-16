// Setup Debug Environment
expRemoveAll

expAdd('filter_in',getNatural())
expAdd('filter_out',getNatural())
expAdd('runFFT',getNatural())
expAdd('fftBufIndex',getNatural())

openAnalysisView('Dual Time','C:/ti/CLA_HandsOnWorkshop/problem/ccs/fft_io.graphProp')
openAnalysisView('Single Time','C:/ti/CLA_HandsOnWorkshop/problem/ccs/fft_mag.graphProp')