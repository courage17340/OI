var
  a:array[1..1000000] of boolean;
  n,i,j:longint;
begin
  fillchar(a,sizeof(a),true);
  a[1]:=false;
  i:=2;
  while i<=1000 do
    begin
      while not a[i] do inc(i);
      for j:=2 to 1000000 div i do a[i*j]:=false;
      inc(i);
    end;
  while true do
    begin
      readln(n);
      if n=0 then break;
      for i:=3 to n shr 1 do
        if a[i] and a[n-i] then
          begin
            writeln(n,' = ',i,' + ',n-i);
            break;
          end;
    end;
end.