var
  a,b,c,n,i:longint;
  p:array[1..9] of 0..1;
begin
  for a:=123 to 333 do
    begin
      b:=a*2;
      c:=a*3;
      fillchar(p,sizeof(p),0);
      p[a mod 10]:=1;p[a div 100]:=1;p[a div 10 mod 10]:=1;
      p[b mod 10]:=1;p[b div 100]:=1;p[b div 10 mod 10]:=1;
      p[c mod 10]:=1;p[c div 100]:=1;p[c div 10 mod 10]:=1;
      n:=0;for i:=1 to 9 do inc(n,p[i]);
      if n=9 then writeln(a,' ',b,' ',c);
    end;
end.