#include "clpp.h"

#include "clppScan_Default.h"
#include "clppScan_GPU.h"

#include "clppSort_RadixSort.h"
#include "clppSort_RadixSortGPU.h"
#include "clppSort_BitonicSort.h"
#include "clppSort_BitonicSortGPU.h"

clppScan* clpp::createBestScan(clppContext* context, size_t valueSize, unsigned int maxElements)
{
	if (context->isGPU)// && context->Vendor == clppVendor::Vendor_NVidia)
		return new clppScan_GPU(context, valueSize, maxElements);

	return new clppScan_Default(context, valueSize, maxElements);
}

clppSort* clpp::createBestSort(clppContext* context, unsigned int maxElements, unsigned int bits)
{
	if (context->isGPU)// && context->Vendor == clppVendor::Vendor_NVidia)
		return new clppSort_RadixSortGPU(context, maxElements, bits, true);

	return new clppSort_RadixSort(context, maxElements, bits, true);
}

clppSort* clpp::createBestSortKV(clppContext* context, unsigned int maxElements, unsigned int bits)
{
	if (context->isGPU)
	{
		if (maxElements < 1000000)
			return new clppSort_BitonicSortGPU(context, maxElements, false);

		return new clppSort_RadixSortGPU(context, maxElements, bits, false);
	}

	// CPU only and small sets
	if (maxElements < 1000000)
		return new clppSort_BitonicSort(context, maxElements, false);

	return new clppSort_RadixSort(context, maxElements, bits, false);
}