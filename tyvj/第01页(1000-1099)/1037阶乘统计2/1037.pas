var
  a:array[1..40] of longint;
  n,k,i,j,x,p,q:longint;
begin
  read(n,k);
  a[40]:=1;
  for i:=2 to n do
    begin
      x:=0;
      for j:=40 downto 1 do
        begin
          a[j]:=a[j]*i+x;
          x:=a[j] div 10;
          a[j]:=a[j] mod 10;
        end;
      j:=40;
      while a[j]=0 do dec(j);
      for p:=40 downto 20 do a[p]:=a[p-(40-j)];
    end;
  for i:=41-k to 40 do write(a[i]);writeln;
end.