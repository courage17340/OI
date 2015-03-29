var
  a:array[1..70000] of boolean;
  i,j,x,ans:longint;
begin
  fillchar(a,sizeof(a),true);
  a[1]:=false;
  i:=2;
  while i<trunc(sqrt(70000)) do
    begin
      while not a[i] do inc(i);
      for j:=2 to 70000 div i do a[i*j]:=false;
      inc(i);
    end;
  while true do
    begin
      readln(x);
      if x=0 then break;
      ans:=0;
      for i:=2 to x shr 1 do
        if a[i] and a[x-i] then inc(ans);
      writeln(ans);
    end;
end.