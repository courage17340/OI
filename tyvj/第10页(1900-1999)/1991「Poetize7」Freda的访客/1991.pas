{f(n)=2^(n div 2+2)-2(n Ææ)
 f(n)=f(n-1)+2^(n/2)(n Å¼)}
var
  a:array[1..100] of longint;
  x,y:int64;
  n,i,j,k:longint;
begin
  readln(n);
  k:=n mod 2;
  k:=(n-1) div 2 +2;
  x:=1;j:=0;
  while k>0 do
    begin
      inc(j);
      a[j]:=k mod 2;
      k:=k div 2;
    end;
  for i:=j downto 1 do
    begin
      x:=int64(x*x) mod 1000000007;
      if a[i]=1 then x:=int64(x*int64(2)) mod 1000000007;
    end;
  if n mod 2=0 then
    begin
      y:=1;
      k:=n div 2;j:=0;
      while k>0 do
        begin
          inc(j);
          a[j]:=k mod 2;
          k:=k div 2;
        end;
      for i:=j downto 1 do
        begin
          y:=int64(y*y) mod 1000000007;
          if a[i]=1 then y:=int64(y*int64(2)) mod 1000000007;
        end;
    end;
  x:=int64(x+y) mod 1000000007;
  x:=x-2;
  if x<0 then x:=x+1000000007;
  writeln(x);
  readln;
end.