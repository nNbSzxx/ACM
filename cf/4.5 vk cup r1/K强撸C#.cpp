using System;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
        	int n;
        	n = Convert.ToInt32(Console.ReadLine());
        	string s;
			s = Console.ReadLine();
            int prekind = 0;
			int cnt = 0;
			bool flag = true;
			for (int i = 0; i < n; i ++) {
				flag = true;
				if ((prekind == 2 && s[i] != 'e')|| (s[i] != 'o' && prekind == 4)) {
					if (cnt <= 2) {
						if (prekind == 2)
						for (int j = 1; j <= cnt; j ++)
							Console.Write("e");
						else
						for (int j = 1; j <= cnt; j ++)
							Console.Write("o");
					} else {
						if (prekind == 2)
						Console.Write("e");
						else
						Console.Write("o");
					}
				}
				switch (s[i]) {
					case 'a':
						if (prekind == 1) {flag = false;cnt++;}
						else prekind = cnt = 1;
						break;
					case 'e':
						if (prekind == 2) {
							cnt ++;
						} else {prekind = 2; cnt=1;}
						flag = false;
						break;
					case 'i':
						if (prekind == 3) {flag = false;cnt++;}
						else {prekind = 3;cnt = 1;}
						break;
					case 'o':
						if (prekind == 4 ) {
							cnt ++;
						} else {prekind = 4; cnt=1;}
						flag = false;
						break;
					case 'u':
						if (prekind == 5) {flag = false;cnt++;}
						else {prekind = 5;cnt = 1;}
						break;
					case 'y':
						if (prekind == 6) {flag = false;cnt++;}
						else {prekind = 6;cnt = 1;}
						break;
					default : cnt = 0; prekind = 0; break;
				}
				if (flag) Console.Write(s[i]);
			}
			if ((prekind == 2 )|| ( prekind == 4)) {
					if (cnt <= 2) {
						if (prekind == 2)
						for (int j = 1; j <= cnt; j ++)
							Console.Write("e");
						else
						for (int j = 1; j <= cnt; j ++)
							Console.Write("o");
					} else {
						if (prekind == 2)
						Console.Write("e");
						else
						Console.Write("o");
					}
				}
			Console.Write("\n");
		}
    }
}
