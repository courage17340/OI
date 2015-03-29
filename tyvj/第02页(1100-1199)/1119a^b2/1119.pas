var
  a:int64;
  n,i,j,d,m,k:longint;
  f:array[0..100] of 0..1;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(d,m);
      a:=1;
      fillchar(f,sizeof(f),0);j:=101;
      while m>0 do
        begin
          dec(j);
          f[j]:=m mod 2;
          m:=m div 2;
        end;
      for k:=j to 100 do
        begin
          a:=a*a mod 1012;
          if f[k]=1 then a:=a*d mod 1012;
        end;
      writeln(a);
    end;
end.