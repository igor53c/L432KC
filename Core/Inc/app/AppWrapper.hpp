#ifndef APPWRAPPER_HPP
#define APPWRAPPER_HPP

#ifdef __cplusplus
extern "C"
{
#endif

	void App_Init();
	void App_Loop();
	void App_Deinit();
	void App_TIM2_IRQHandler();

#ifdef __cplusplus
}
#endif

#endif // APPWRAPPER_HPP
