To run tests, type the following in the command line:
    make
    ./containers >>  file1.txt
    ./containers_std >> file2.txt
    diff file1.txt file2.txt


        if (lib == STD)
    {
        test[0] = (pair1.first) == (0);
        test[1] = (pair1.second) == (NULL);
        test[2] = (pair2.first) == (100);
        test[3] = (pair2.second) == ('G');
        test[4] = () == ();
        test[5] = () == ();
        test[6] = () == ();
        test[7] = () == ();
        test[8] = () == ();
        test[9] = () == ();
        test[10] = () == ();
        test[11] = () == ();
        test[12] = () == ();
        test[13] = () == ();
        test[14] = () == ();
        test[15] = () == ();
        test[16] = () == ();
        test[17] = () == ();
        test[18] = () == ();
        test[19] = () == ();
        test[20] = () == ();
        test[21] = () == ();
        test[22] = () == ();
        test[23] = () == ();
        test[24] = () == ();
        test[25] = () == ();
        test[26] = () == ();
        test[27] = () == ();
        test[28] = () == ();
    }


    for(int i = 0 ; i < nb_test ; i++)
    {
        if(test[i] == true)
            std::cout << "\033[32m[   PASSED   ]\033[37m   Test " << i << std::endl;
        else
            std::cout << "\033[31m[!!!FAILED!!!]\033[37m   Test " << i << std::endl;
    }