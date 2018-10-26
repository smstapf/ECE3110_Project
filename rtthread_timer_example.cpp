void* ADCthread(void* ptr) { //controls ADC
  int timer_fd = timerfd_create(CLOCK_MONOTONIC, 0); //intialize timer for 1 khz
	 if(timer_fd == -1) {
		 	printf("Error creating timer");
		 	exit(0);
	 }
	 struct itimerspec timerspec;
	 timerspec.it_interval.tv_sec = 0;
	 timerspec.it_interval.tv_nsec = 1000000;
	 timerspec.it_value.tv_sec = 0;
	 timerspec.it_value.tv_nsec = 1000000;
	 if(timerfd_settime(timer_fd,0,&timerspec,NULL) == -1) {
	 	 printf("Error starting timer");
	 	 exit(0);
	 }
	 struct sched_param param; //schedule as real time task
	 param.sched_priority = 48;
	 sched_setscheduler(0,SCHED_FIFO,&param);
	 uint64_t num_periods = 0;

   AnalogInput *adc = (AnalogInput*)ptr; //grab adc pointer from argument

    while(1) {
      while(read(timer_fd, &num_periods,sizeof(num_periods)) == -1); //wait for timer
  		if(num_periods >  1) {puts("MISSED WINDOW");exit(1);} //error check
           adc->update(); //call update method
    }
    //thread should never exit
    //pthread_exit((void*)retval);
}