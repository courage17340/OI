var
  f:array[1..1000000] of boolean;
  n,i,j,k,a,d,ans:longint;
begin
  fillchar(f,sizeof(f),true);
  f[1]:=false;
  i:=2;
  while i<1000 do
    begin
      while not f[i] do inc(i);
      for j:=2 to 1000000 div i do f[i*j]:=false;
      inc(i);
    end;
  while true do
    begin
      readln(a,d,n);
      if a+d+n=0 then break;
      k:=0;
      for ans:=0 to 1000000 div d do
        if f[ans*d+a] then
          begin
            inc(k);
            if k=n then break;
          end;
      writeln(ans*d+a);
    end;
end.