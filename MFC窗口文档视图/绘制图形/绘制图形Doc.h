
// 绘制图形Doc.h : C绘制图形Doc 类的接口
//


#pragma once


class C绘制图形Doc : public CDocument
{
protected: // 仅从序列化创建
	C绘制图形Doc();
	DECLARE_DYNCREATE(C绘制图形Doc)

	CObList  m_LineList;//一系列线段的链表
// 特性
public:
	CObject *GetLineList();
	void DeleteContents();//删除文档内容，当文档被关闭，打开或新建使，应用程序会自动调用该函数
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~C绘制图形Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
