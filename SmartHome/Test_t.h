#ifndef __TEST_T_H__
#define __TEST_T_H__

class Test_t {
public:
	explicit Test_t(vector<ISensorLogic*>& _testSensors);
	virtual void RunTest();
		

private:
	Test_t(const Test_t&);
	const Test_t& operator=(const Test_t&);
	vector<ISensorLogic*> m_testSensors;
	
	void Print() const;
	void SetValue();
};

#endif /* __TEST_T_H__ */

