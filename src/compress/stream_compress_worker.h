#ifndef STREAM_COMPRESS_WORKER_H
#define STREAM_COMPRESS_WORKER_H

#include <napi.h>
#include <uv.h>
#include "stream_compressor.h"

namespace ZSTD_NODE {

  using Napi::AsyncWorker;
  using Napi::FunctionReference;

  class StreamCompressWorker : public AsyncWorker {
  public:
    StreamCompressWorker(FunctionReference *callback, StreamCompressor *sc, bool isLast);
    ~StreamCompressWorker();

  private:
    void pushToPendingOutput();

    StreamCompressor *sc;
    ZSTD_outBuffer zOutBuf;
    ZSTD_inBuffer zInBuf;
    bool isLast;
    size_t ret;
  };

}

#endif
