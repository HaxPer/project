#import "Skype4COM.dll" 

int _tmain(int argc, _TCHAR* argv[]) {
	// �������������� COM ���������� 
	CoInitialize(NULL);

	// ������� Skype ������ 
	SKYPE4COMLib::ISkypePtr pSkype(__uuidof(SKYPE4COMLib::Skype));

	// ����������� � Skype API 
	pSkype->Attach(6, VARIANT_TRUE);

	// �������� ������ ������� � ������� �� 
	_bstr_t bstrSkypeVersion = pSkype->GetVersion();
	printf("Skype client version %s\n", (char*)bstrSkypeVersion);

	//�������� ������ COM "�������" 
	_bstr_t bstrWrapperVersion = pSkype->GetApiWrapperVersion();
	printf("COM wrapper version %s\n", (char*)bstrWrapperVersion);

	// ������� ���������� �� ����� 
	pSkype = NULL;
	CoUninitialize();

	return 0;
}