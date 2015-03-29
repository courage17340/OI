var
  w1,w2,i,d1,d2:longint;
  a:array[0..200000] of longint;
begin
  read(w1,w2,d1,d2);
  w1:=w1-w2;
  fillchar(a,sizeof(a),0);
  a[w1]:=1;
  for i:=w1-1 downto 0 do
    a[i]:=a[i+d1]+a[i+d2];
  writeln(a[0]);
  readln;readln;
end.