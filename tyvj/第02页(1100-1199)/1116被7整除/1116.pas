var n:longint;
begin
 readln(n);
 if n mod 21>=15 then writeln(n div 21*6+6)
 else if n mod 21>=10 then writeln(n div 21*6+5)
 else if n mod 21>= 6 then writeln(n div 21*6+4)
 else if n mod 21>= 5 then writeln(n div 21*6+3)
 else if n mod 21>= 4 then writeln(n div 21*6+2)
 else if n mod 21>= 2 then writeln(n div 21*6+1)
 else writeln(n div 21*6);
end.