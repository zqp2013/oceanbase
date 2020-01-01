////===================================================================
 //
 // liboblog.h liboblog / Oceanbase
 //
 // Copyright (C) 2013 Alipay.com, Inc.
 //
 // Created on 2013-05-23 by Yubai (yubai.lk@alipay.com) 
 //
 // -------------------------------------------------------------------
 //
 // Description
 // 
 //
 // -------------------------------------------------------------------
 // 
 // Change Log
 //
////====================================================================

#ifndef  OCEANBASE_LIBOBLOG_H_
#define  OCEANBASE_LIBOBLOG_H_

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#endif

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS
#endif

#include <stdint.h>
#include <vector>
#include "ob_define.h"
//#include "MD.h"
//#include "BR.h"

namespace oceanbase
{
  namespace liboblog
  {
    class IObLogSpec
    {
      public:
        virtual ~IObLogSpec() {};
      public:
        /*
         * ��ʼ��
         * @param config      �����ļ�·����url��ַ
         * @param checkpoint  �Ӽ��㿪ʼץȡ��־
         */
        virtual int init(const char *config, const uint64_t checkpoint) = 0;
        virtual void destroy() = 0;
        virtual int launch() = 0;
    };

    class IObLog;
    class ObLogSpecFactory
    {
      public:
        ObLogSpecFactory();
        ~ObLogSpecFactory();
      public:
        IObLogSpec *construct_log_spec();
        IObLog *construct_log();
        void deconstruct(IObLogSpec *log_spec);
        void deconstruct(IObLog *log);
    };

    class IObLog    
    {
      public:
        virtual ~IObLog() {};

      public:
        /*
         * ��ʼ��
         * @param log_spec    ȫ��ʹ��һ��log_spec
         * @param partition   ץȡָ������������
         * @return 0:�ɹ�
         */
        virtual int init(IObLogSpec *log_spec, const std::vector<uint64_t> &partitions) = 0;

        /*
         * ����
         */
        virtual void destroy() = 0;

        /*
         * ����һ�����ݿ�statement
         * @param record      ����record����ַ���ڲ����䣬�����ε���record֮���ٵ���release
         * @param 0:�ɹ�
         */
        virtual int next_record(IBinlogRecord **record, const int64_t timeout_us) = 0;

        /*
         * �ͷ�record
         * @param record
         */
        virtual void release_record(IBinlogRecord *record) = 0;
    };
  }
}

#endif //OCEANBASE_LIBOBLOG_H_

