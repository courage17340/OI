var
  n,i,j,k:longint;
  a:array[0..1000000] of longint;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    begin
      read(j,k);
      a[i]:=j+k;
    end;
  j:=0;
  for i:=n downto 1 do
    begin
      a[i]:=a[i]+j;
      j:=a[i] div 10;
      a[i]:=a[i] mod 10;
    end;
  for i:=1 to n do write(a[i]);
  writeln;
end.