#import "Skype4COM.dll" 

int _tmain(int argc, _TCHAR* argv[]) {
	// Инициализмруем COM соединение 
	CoInitialize(NULL);

	// Создаем Skype объект 
	SKYPE4COMLib::ISkypePtr pSkype(__uuidof(SKYPE4COMLib::Skype));

	// Соединяемся с Skype API 
	pSkype->Attach(6, VARIANT_TRUE);

	// Получаем версию клиента и выводим ее 
	_bstr_t bstrSkypeVersion = pSkype->GetVersion();
	printf("Skype client version %s\n", (char*)bstrSkypeVersion);

	//Печатаем версию COM "обертки" 
	_bstr_t bstrWrapperVersion = pSkype->GetApiWrapperVersion();
	printf("COM wrapper version %s\n", (char*)bstrWrapperVersion);

	// Удаляем соединения со скайп 
	pSkype = NULL;
	CoUninitialize();

	return 0;
}