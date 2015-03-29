var
  a:array[1..6] of longint;
  pan:array[0..120000] of boolean;
  s,i,j,max,k:longint;
begin
  while true do
    begin
      for i:=1 to 6 do read(a[i]);
      s:=0;
      for i:=1 to 6 do s:=s+a[i]*i;
      if s=0 then halt;
      if s mod 2=1 then writeln('Can''t')
        else
          begin
            fillchar(pan,sizeof(pan),false);
            for i:=0 to a[6] do pan[i*6]:=true;
            max:=a[6]*6;
            for i:=1 to 5 do
              for j:=1 to a[i] do
                begin
                  max:=max+i;
                  for k:=max downto i do pan[k]:=pan[k] or pan[k-i];
                  if pan[s shr 1] then break;
                end;
            if pan[s shr 1] then writeln('Can') else writeln('Can''t');
          end;
    end;
end.
