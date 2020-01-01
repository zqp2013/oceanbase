/**
 * Copyright (c) 2012 Taobao.com
 * All rights reserved.
 *
 * �ļ����ƣ�MetaData.h
 * ժҪ��db��table��column��meta��Ϣ��ȡ�ӿ�
 * ���ߣ�Benkong <benkong@taobao.com>
 * ���ڣ�2012.5.22
 */
#ifndef _META_DATA_H_
#define _META_DATA_H_

//#include "MD.h"

namespace oceanbase
{
namespace liboblog
{

// column��������Ϣ
struct ColMetaInfo;
class ColMeta : public IColMeta
{
public:
	ColMeta();
	ColMeta(const void *ptr, size_t size);
	virtual ~ColMeta();

public:
	// override
	virtual const char *getName();
	virtual int getType();
	virtual long getLength();
	virtual bool isSigned();
	virtual bool isPK();
	virtual bool isNotNull();
	virtual int getDecimals();
	virtual const char* getDefault();
	virtual const char* getEncoding();
	virtual int getRequired();
	virtual IStrArray* getValuesOfEnumSet();

	virtual void setName(const char* name);
	virtual void setType(int type);
	virtual void setLength(long length);
	virtual void setSigned(bool b);
	virtual void setIsPK(bool b);
	virtual void setNotNull(bool b);
	virtual void setDecimals(int decimals);
	virtual void setDefault(const char* def);
	virtual void setEncoding(const char* enc);
	virtual void setRequired(int required);
	virtual void setValuesOfEnumSet(std::vector<std::string> &v);
	virtual void setValuesOfEnumSet(std::vector<const char*> &v);
	virtual void setValuesOfEnumSet(const char** v, size_t size);

public:
	int appendTo(std::string &s);
	size_t getRealSize();
	int parse(const void *ptr, size_t size);
	bool parsedOK();
private:
	ColMetaInfo *m_col;
};

// table��������Ϣ
struct TableMetaInfo;
class TableMeta : public ITableMeta
{
public:
	TableMeta();
	TableMeta(const void *ptr, size_t size);
	virtual ~TableMeta();

public:
	// override
	virtual const char* getName();
	virtual bool hasPK();
	virtual const char* getPKs();
	virtual const char* getEncoding();
	virtual IDBMeta* getDBMeta();

	virtual void setName(const char* name);
	virtual void setHasPK(bool b);
	virtual void setPKs(const char* pks);
	virtual void setEncoding(const char* enc);
	virtual void setDBMeta(IDBMeta* dbMeta);

public:

    /**
     * ��������ֶ���
     */
    std::vector<std::string> &getColNames();

    /**
     * PK column����
     */
    std::vector<std::string> &getPKColNames();

    /**
	 * ͨ��column�����ֻ�ȡĳ��column��meta��Ϣ
	 * @param colName   column������
	 * @return NULL: û��colName��Ӧ��������Ϣ; ��NULL: colName��Ӧ��������Ϣ
	 */
	virtual IColMeta* getCol(const char* colName);

	/**
	 * ��ȡColumn��Ŀ
	 * @return Column��Ŀ
	 */
	virtual int getColCount();

	/*
	 * ͨ��column��mysql�е��ڲ���ŵõ�ĳ��column��meta��Ϣ
	 *
	 * @param index column�����к�
	 * @return NULL: û��colName��Ӧ��������Ϣ; ��NULL: colName��Ӧ��������Ϣ
	 */
	virtual IColMeta* getCol(int index);
	virtual int getColNum(const char* colName);

	/**
	 * ׷��һ��column��������Ϣ
	 * @param colName  column����
	 * @param colMeta  column��������Ϣ
	 * @return 0: �ɹ��� <0: ʧ��
	 */
	virtual int append(const char* colName, IColMeta *colMeta);

public:
	int appendTo(std::string &s);
	size_t getRealSize();
	int parse(const void *ptr, size_t size);
	bool parsedOK();
private:
    TableMetaInfo *m_tbl;
};

// DB��������Ϣ
struct DBMetaInfo;
class DBMeta : public IDBMeta
{
public:
	DBMeta();
	DBMeta(const void *ptr, size_t size);
	virtual ~DBMeta();

public:
	// override
	virtual const char* getName();
	virtual const char* getEncoding();
	virtual IMetaDataCollections* getMetaDataCollections();

	virtual void setName(const char* name);
	virtual void setEncoding(const char* enc);
	virtual void setMetaDataCollections(IMetaDataCollections *mdc);

    virtual int getTblCount();
	/**
	 * ��ȡָ��table��������Ϣ
	 * @param tblName  table����
	 * @return NULL: û��tblName��Ӧ��������Ϣ; ��NULL: tblName��Ӧ��������Ϣ
	 */
	virtual ITableMeta* get(const char* tblName);
    virtual ITableMeta* get(int index);

	/**
	 * ����һ��table������Ϣ
	 * @param tblName  table����
	 * @param tblMeta  table������Ϣ
	 * @return 0: �ɹ�; <0: ʧ��
	 */
	virtual int put(const char* tblName, ITableMeta *tblMeta);
public:
	int appendTo(std::string &s);
	size_t getRealSize();
	int parse(const void *ptr, size_t size);
	bool parsedOK();
private:
	DBMetaInfo *m_db;
};

// meta data���ϣ��������е�db��������Ϣ
struct MetaDataCollectionInfo;
class MetaDataCollections : public IMetaDataCollections
{
public:
	MetaDataCollections();
	MetaDataCollections(const void *ptr, size_t size, bool removePtr=false); // removePtr��ʾ�Ƿ���Ҫ������ʱ�ͷ�ptr
	virtual ~MetaDataCollections();

public:
	// override
	virtual unsigned getMetaVerNum();
	virtual IMetaDataCollections* getPrev();
	virtual time_t getTimestamp();

	virtual void setMetaVerNum(unsigned metaVerNum);
	virtual void setPrev(IMetaDataCollections* prev);
	virtual void setTimestamp(time_t timestamp);

    /**
     * ��ȡDb����Ŀ
     * @return Db����Ŀ
     */
    virtual int getDbCount();

    /**
     * ��ȡָ�����Ƶ�Db������Ϣ
     * @param dbname ָ������
     * @return ָ��Db��������Ϣ
     */
    virtual IDBMeta *get(const char* dbname);

    /**
     * ��ȡָ��λ�õ�Db������Ϣ
     * @param index ָ��λ��
     * @return ָ��Db��������Ϣ
     */
    virtual IDBMeta *get(int index);

    /**
	 * ��ȡָ��table��������Ϣ
	 * @param dbName   db����
	 * @param tblName  table����
	 * @return NULL: û��tblName��Ӧ��������Ϣ; ��NULL: tblName��Ӧ��������Ϣ
	 */
	virtual ITableMeta* get(const char* dbName, const char* tblName);

	/**
	 * ����һ��db������Ϣ
	 * @param dbName  db����
	 * @param dbMeta  db������Ϣ
	 * @return 0: �ɹ�; <0: ʧ��
	 */
	virtual int put(const char* dbName, IDBMeta *dbMeta);

    /**
     * ���л�Ϊ�ַ���
     * @param s  �������л���Ľ��
     * @return 0: �ɹ�; <0: ʧ��
     */
	virtual int toString(std::string& s);

	/**
	 * ����ֻ����¼
     * @param ptr   ������
     * @param size  ptr��ռ�ֽ���
	 * @return 0:�ɹ���<0: ʧ��
	 */
	virtual int parse(const void* ptr, size_t size);

	/**
	 * �����Ƿ�ɹ�
	 * @return true/false
	 */
	virtual bool parsedOK();

	/**
	 * ֻ��������ʵ����Ч���ֽ�����parse()��ʱ������size�ȱ���Ч���ݳ�
	 * @return �ֽ���
	 */
	virtual size_t getRealSize();
private:
	MetaDataCollectionInfo *m_coll;
};

}
}

#endif

