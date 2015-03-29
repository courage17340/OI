var
  a:array[1..100000] of boolean;
  b:array[0..100000] of longint;
  i,j:longint;
begin
  fillchar(a,sizeof(a),true);
  a[1]:=false;
  i:=1;
  while i<=trunc(sqrt(100000)) do
    begin
      while not a[i] do inc(i);
      for j:=2 to 100000 div i do
        a[i*j]:=false;
      inc(i);
    end;
  fillchar(b,sizeof(b),0);
  for i:=2 to 100000 do if a[i] then b[i]:=b[i-1]+1 else b[i]:=b[i-1];
  while true do
    begin
      readln(i,j);
      if i=-1 then break;
      if i<1 then i:=1;
      writeln(b[j]-b[i-1]);
    end;
end.